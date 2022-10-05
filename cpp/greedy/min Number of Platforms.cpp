int calculateMinPatforms(int at[], int dt[], int n)
{
    // Write your code here.
    sort(at, at + n);
    sort(dt, dt + n);

    int i = 0, j = 0;
    int minResult = 0, curr = 0;

    while (i < n)
    {
        if (at[i] <= dt[j])
        {
            curr++;
            i++;
        }
        else
        {
            curr--;
            j++;
        }

        minResult = max(minResult, curr);
    }

    return minResult;
}