file="records.txt"

create() {
    if test -f $file; then
        echo 'file already present'
    else
        touch $file
        echo 'file is created'
    fi
}

insert() {
    echo 'enter name'
    read name
    echo 'enter no.'
    read number
    echo "$name-$number" >>$file
    echo 'record inserted'
}

display() {
    nl $file
}

find() {
    echo 'enter the name'
    read name
    re=$(grep -i $name $file)
    if test -z $re; then
        echo 'detail not found'
    else
        echo 'details'
        echo $re
    fi
}

del() {
    echo 'enter the name'
    read name
    sed -i "/$name/d" $file
    echo "$name deleted"
}

while [ 1 -gt 0 ]; do
    echo "Select the Opetion"
    echo "1. create"
    echo "2. insert"
    echo "3. display"
    echo "4. find"
    echo "5. delete"
    echo "6. exit"
    echo '**************'
    read choice
    case "${choice}" in
    1) create ;;
    2) insert ;;
    3) display ;;
    4) find ;;
    5) del ;;
    6) exit 1 ;;
    *) echo"wrong choice" ;;
    esac
    echo '**************'
done
