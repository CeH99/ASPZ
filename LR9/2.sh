echo "Спроба прочитати /etc/shadow без sudo (очікується помилка):"
cat /etc/shadow 2>/dev/null || echo "-> Очікувана помилка: Permission denied"

echo -e "\nЧитання /etc/shadow за допомогою sudo (виводимо перші 3 рядки):"
sudo cat /etc/shadow | head -n 3