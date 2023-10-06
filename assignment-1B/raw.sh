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

update(){
    echo 'enter the name'
    read old_name;
    echo 'enter new name'
    read new_name;
    echo 'enter new number'
    read new_no;

    sed -i "s/$old_name-.*$/$new_name-$new_no/g" $file

    echo "$old_name updated"
}

while [ 1 -gt 0 ]; do
    echo "Select the Opetion"
    echo "1. create"
    echo "2. insert"
    echo "3. update"
    echo "4. display"
    echo "5. find"
    echo "6. delete"
    echo "7. exit"
    echo '**************'
    read choice
    case "${choice}" in
    1) create ;;
    2) insert ;;
    3) update ;;
    4) display ;;
    5) find ;;
    6) del ;;
    7) exit 1 ;;
    *) echo"wrong choice" ;;
    esac
    echo '**************'
done
