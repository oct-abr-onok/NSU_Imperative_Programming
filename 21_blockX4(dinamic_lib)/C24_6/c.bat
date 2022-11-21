cl hashmap.c -LD -Fehashmap.dll -D HASHMAP_EXPORTS
cl -O2 main.c hashmap.lib -Fechecked_solution.exe