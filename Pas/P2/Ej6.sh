#!/bin/bash                                                                                                                                                                                                                                   
lines=$(cat /etc/group | sed -rn 's/^([a-z\-]*):.:([0-9]*):.*/\2,\1/p')

for x in $lines ; do
        index=$(echo $x | grep -Eo '[0-9]*')
        word=$(echo $x | grep -Eo '[a-z\-]*')
        group["$index"]="$word"
done

passwd=$(cat /etc/passwd | sed -rn 's/^([a-z\-]*):x:([0-9]*):([0-9]*):([a-zA-Z\-\/]*):([\/a-z]*):([\/a-z]*)/logname:·\1;->IUD:·\2;->GUID:·\3;->group:·xxx;->gecos:·\4;->home:·\5;->shell:·\6/p' | grep $1)

for u in $passwd ; do
        GUID=$(echo "$u" | sed -rn 's/.*GUID:·([0-9]*).*/\1/p')
        for u_ in $(users) ; do
                if [[ "$(echo "$u" | sed -rn 's/logname:·([a-zA-Z\-]*).*/\1/p')" == "$u_" ]]; then
                        i=1
                        break
                else
                        i=0
                fi
        done
        echo "pito"
        printf "${group[$GUID]}-$u" | sed -rn 's/(^[a-z]*)-(.*)xxx(.*$)/\2\1\3/p' | tr ';' '\n' | tr '_' '\t' | tr '·' ' '
        printf "\n->loged: $i\n"
done