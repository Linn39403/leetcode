bool isPalindrome(int x)
{
    char x_str[12] = {0};
    char x_str_rev[12] = {0};
    int x_length = 0;
    //convert x to str 
    sprintf(x_str,"%d",x);
    x_length = strlen(x_str);

    //reverse x str and copy to x_str_rev arr
    for(int i = 0; i < x_length; i++)
    {
        x_str_rev[x_length-i-1] = x_str[i];
    }

    return strcmp(x_str,x_str_rev) == 0 ? true : false;
}