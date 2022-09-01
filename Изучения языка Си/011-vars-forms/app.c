
// echo %errorlevel% - kod otveta na Windows

int func_three();
int func_four();

int main()
{
    
    // obyavlenie i initialization by Literal
    int v1 = 1;
    int v2 = 2;

    // obyavlenie i initialization and ob'yavlenie by funtion
    int v3 = func_three();
    int v4 = func_four();

    int v7 = v3 + v4;

    // v etih peremennyh lezhit musor
    // int v5, v6, v7;

    int a = 0, b = 0, c = 0;
    
    return 0;
}

int func_three()
{
    return 3;
}

int func_four()
{
    return 4;
}
