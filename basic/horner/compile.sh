if [ $# -ne 1 ]; then
    echo "指定された引数は$#個です。" 
    echo "実行するには1個の引数が必要です。" 
    exit 1
fi

gcc -o $1.exe $1.c ../../helpers/ary.c
