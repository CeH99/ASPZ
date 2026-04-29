TEMP_FILE="temp_perms_test.txt"

echo "Створення тимчасового файлу..."
touch "$TEMP_FILE"

echo "Зміна власника на root..."
sudo chown root:root "$TEMP_FILE"

echo -e "\n--- Тест 1: Права 600 (тільки root має rw) ---"
sudo chmod 600 "$TEMP_FILE"
echo -n "Читання: " && cat "$TEMP_FILE" 2>/dev/null || echo "Відмовлено"
echo -n "Запис: " && echo "test" > "$TEMP_FILE" 2>/dev/null || echo "Відмовлено"

echo -e "\n--- Тест 2: Права 644 (root - rw, інші - r) ---"
sudo chmod 644 "$TEMP_FILE"
echo -n "Читання: " && cat "$TEMP_FILE" 2>/dev/null && echo "Успішно (файл пустий)"
echo -n "Запис: " && echo "test" > "$TEMP_FILE" 2>/dev/null || echo "Відмовлено"

echo -e "\n--- Тест 3: Права 666 (всі мають rw) ---"
sudo chmod 666 "$TEMP_FILE"
echo -n "Читання: " && cat "$TEMP_FILE" 2>/dev/null && echo "Успішно"
echo -n "Запис: " && echo "test" > "$TEMP_FILE" 2>/dev/null && echo "Успішно"

sudo rm -f "$TEMP_FILE"