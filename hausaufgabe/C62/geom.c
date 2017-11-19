int is_geom(double *array, unsigned array_size)
{
    if(array_size < 2) return -1;        //0 oder 1 gliedige Arrays wird immer oder nie als eine geometrische Folge behandelt, von den Implementation abhaengig
    double d = array[1] - array[0];
    for(int i = 2; i<array_size; i++)
    {
        if(array[i] - array[i-1] != d) return 0;
    }
    return 1;
}