TARGET_DIR="/opt/secure_dir"
GROUP_NAME="secure_group"
CURRENT_USER=$(whoami)

echo "1. Створюємо групу $GROUP_NAME..."
sudo groupadd -f "$GROUP_NAME"

echo "2. Створюємо цільову директорію $TARGET_DIR..."
sudo mkdir -p "$TARGET_DIR"

echo "3. Налаштовуємо власника та права (root:secure_group, chmod 070)..."
# 070 означає: власник (0) - нічого, група (7) - rwx, інші (0) - нічого
sudo chown root:"$GROUP_NAME" "$TARGET_DIR"
sudo chmod 070 "$TARGET_DIR"

echo "4. Додаємо користувача $CURRENT_USER до створеної групи..."
sudo usermod -aG "$GROUP_NAME" "$CURRENT_USER"

echo -e "\nНалаштування завершено! Перевірка прав:"
ls -ld "$TARGET_DIR"