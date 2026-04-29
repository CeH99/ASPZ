echo "--- Права доступу на домашній каталог (~) ---"
ls -ld ~

echo -e "\n--- Права доступу на /usr/bin ---"
ls -ld /usr/bin

echo -e "\n--- Права доступу на /etc ---"
ls -ld /etc

echo -e "\n--- Спроби взаємодії ---"
echo -n "Спроба запису в /etc/passwd: "
echo "test" > /etc/passwd 2> err.log && echo "Успіх" || cat err.log

echo -n "Спроба виконання /usr/bin/ls: "
/usr/bin/ls -d /usr/bin > /dev/null 2>&1 && echo "Успішно" || echo "Відмовлено"

rm -f err.log