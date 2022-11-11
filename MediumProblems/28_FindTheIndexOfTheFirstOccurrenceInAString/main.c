int strStr(char * haystack, char * needle)
{
    int haystack_length = strlen(haystack);
    int needle_length = strlen(needle);
    int i = 0;
    int j = 0;

    if(needle_length == 0)
    {
        return 0;
    }

    if(needle_length > haystack_length)
    {
        return -1;
    }

    for(i = 0; i < haystack_length; i++)
    {
        for(j = 0; j < needle_length; j++)
        {
            if(haystack[i+j] != needle[j])
            {
                break;
            }
        }

        if(j == needle_length)
        {
            return i;
        }
    }

    return -1;
}