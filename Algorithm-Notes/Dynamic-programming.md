##### Useful link

https://www.cnblogs.com/Christal-R/p/Dynamic_programming.html

##### Note

1.  新建数组时(无论是`f`还是`w`和`v`), 都要多建一位, 并把0的地方填0

## 01背包问题

### 无优化

```c++
for (int i = 1; i <= n; i++)
{
  for (int c = 0; c <= m; c++)
  {
    f[i][c] = f[i-1][c];
    if (c >= w[i])
    	f[i][c] = max(f[i][c], f[i-1][c-w[i]] + v[i]);
  }
}
```

### 一维数组优化

```c++
for (int i = 1; i <= n; i++)
{
  for (int c = m; c >= 0; c--)
  {
    if (c >= w[i])
      f[c] = max(f[c], f[c-w[i]] + v[i]);
  }
}
```

### 常数优化

(看不懂)

```c++
for (int i = 1; i <= n; i++)
{
  sumw += w[i];
  bound = max(m-sumw, w[i]);
  for (int c = m; c >= bound; c--)
  {
    if (c >= w[i])
      f[c] = max(f[c], f[c-w[i]] + v[i]);
  }
}
```

## 完全背包问题

```c++
for(int i=1;i<=n;i++)
{
    for(int c=0;c<=m;c++)
    {
        if(c>=w[i])
        	f[c]=max(f[c],f[c-w[i]]+v[i]);
    }
}
```

## 多重背包问题

```c++
for(int i=1;i<=n;i++)
{
    if(w[i]*a[i]>m)
    {
        for(int c=0;c<=m;c++)
        {
        if(c>=w[i])
        	f[c]=max(f[c],f[c-w[i]]+v[i]);
        }
    }
    else
    {
         k=1;amount=a[i];
         while(k<amount)
         {
             for(int c=k*w[i];c>=0;c--)
             {
               if(c>=w[i])
                 f[c]=max(f[c],f[c-w[i]]+k*v[i]);
             }
             amount-=k;
             k<<=1;
         }  
         for(int c=amount*w[i];c>=0;c--)
         {
             f[c]=max(f[c],f[c-w[i]]+amount*v[i]);
         }
    } 
}
```

