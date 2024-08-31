char * mergeAlternately(char * word1, char * word2)
{
    int w1_len = strlen(word1);
    int w2_len = strlen(word2);
    char * merge_w = calloc((w1_len+w2_len+1),sizeof(char));
    int min_idx = w1_len > w2_len ? w2_len : w1_len;
    int idx = 0, merge_idx = 0;
    for(idx = 0; idx < min_idx; idx++)
    {
        merge_w[merge_idx++] = word1[idx];
        merge_w[merge_idx++] = word2[idx];
    }
    if(min_idx < w1_len)
    {
        for(; idx < w1_len; idx++){
            merge_w[merge_idx++] = word1[idx];
        }
    }
    else if(min_idx < w2_len)
    {
        for(; idx < w2_len; idx++){
            merge_w[merge_idx++] = word2[idx];
        }
    }
    else
    {

    }
    return merge_w;
}