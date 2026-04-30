
CURRENT_USER=$(whoami)
echo "Звичайні користувачі в системі (UID >= 1000), окрім $CURRENT_USER:"

getent passwd | awk -v curr="$CURRENT_USER" -F: '$3 >= 1000 && $1 != curr {print "Користувач: "$1", UID: "$3}'