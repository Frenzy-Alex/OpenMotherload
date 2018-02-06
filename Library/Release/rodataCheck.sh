objcopy -S --impure -j .rodata ./libACE.so ./_rodata
cat _rodata | sed 's/\x0/\n/g' | sort | uniq -c

