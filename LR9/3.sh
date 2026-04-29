USER_HOME=$(eval echo ~$USER)
FILE_NAME="root_copy_test.txt"
USER_FILE="/tmp/user_original.txt"
ROOT_COPY="$USER_HOME/$FILE_NAME"

echo "1. Створюємо файл від імені звичайного користувача..."
echo "Original content" > "$USER_FILE"

echo "2. Копіюємо файл від імені root у домашній каталог користувача..."
sudo cp "$USER_FILE" "$ROOT_COPY"

echo "3. Спроба зміни файлу звичайним користувачем..."
echo "New content" > "$ROOT_COPY" 2> error.log
cat error.log

echo "4. Спроба видалення файлу звичайним користувачем..."
rm -f "$ROOT_COPY" 2> rm_error.log
if [ ! -f "$ROOT_COPY" ]; then
    echo "-> Файл успішно видалено! (Бо є права на запис у домашній каталог)"
else
    cat rm_error.log
fi

rm -f "$USER_FILE" error.log rm_error.log