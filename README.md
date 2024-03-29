# Competitive programming
A collection of solutions and resources for competitive programming.

This is the fish function I use to execute CPP files in the terminal.

```bash
function exc
    set bin (string replace -r '.cpp$' '' $argv)
    g++ -Wall -Wextra -DLOCAL -std=c++17 $argv -o $bin  && ./$bin && rm $bin
end
```

Without the function would be:
```bash
g++ -Wall -Wextra -DLOCAL -std=c++17 filename.cpp -o filename  && ./filename && rm filename 
```

Here is my notebook with implementations for several algorithms and data structures (forked from [DescomUNAL](https://github.com/ahoraSoyPeor/notebook_descomUNAL)): [Notebook](https://github.com/DaniDiazTech/notebook_UNAL).

