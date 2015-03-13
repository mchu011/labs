#ifndef MYCSTRING_H
#define MYCSTRING_H

char* mystrcpy(char* dest, const char* from)
{
	int i;
	for(i = 0; from[i]; i++)
	{
		dest[i] = from[i];
	}
	dest[i] = '\0'; 
	return dest;
}

/*char* strncpy(char* dest, const char* from, size_t x )
{
	int i;
	for(i = 0; i < x && from[i]; i++)
	{
		dest[i] = from[i];
	}
	dest[i] = '\0';
	return dest;
}*/

char* mystrcat(char* dest, const char* from)
{
	int count = 0;
	for(int i = 0; dest[i]; i++)
	{
		count++;
	}
	
	int j;
	for(j = 0; from[j]; j++)
	{
		dest[count+j] = from[j];
	}
	dest[count+j] = '\0';
	return dest;	
}

/*strncat()
{

}*/

int  mystrlen(const char*s)
{
	int i = 0;
	for(;s[i] != '\0'; i++)
	{
	}
	return i;
}

int mystrcmp(const char* s1, const char* s2)
{
	int count1 = mystrlen(s1);
	
	int count2 = mystrlen(s2);

	if(count1 == count2)
	{
		int k;
		for(k = 0; k < count1; k++)
		{
			if(s1[k] > s2[k])
			{
				return 1;
			}
			else if(s1[k] < s2[k])
			{
				return -1;
			}
		}
		return 0;
	}
	else if (count1 > count2)
	{
		return 1;
	}
	else if(count1 < count2)
	{
		return -1;
	}
}

/*mystrchr()
{

}*/

/*const char* mystrstr(const char* s1, const char* s2) // don't include this
{
	const char* ret = '\0';
	int i = 0;
	while(s1[i] != '\0')
	{
		if(s1[i] == s2[0])
		{
			ret = i;
			for(int j = 0; s2[j]; j++)
			{
				for(int k = i; s2[j] && s1[k]; k++)
				{
					if(s2[j] !=s1[k])
					{
						ret = '\0';
					}
				}
			}	

		}
		i++;
	}
	return ret;
}*/

char* mystrstr(char* s1, const char* s2)
{
	char* ret = '\0';
	int i = 0;
	while(s1[i] != '\0')
	{
		if(s1[i] == s2[0])
		{
			ret = &s1[i];
			int k = i;
			for(int j = 0; s2[j] && s1[k]; j++)
			{			
				if(s2[j] !=s1[k])
				{
					ret = '\0';
				}
				k++;
			}	

		}
		i++;
	}		
	return ret;
}


#endif
