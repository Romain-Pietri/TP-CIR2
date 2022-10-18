template<typename Iter>
typename Iter::value_type
partial_dot(Iter first1,Iter last1,Iter first2,Iter last2)//calcul le produit scalaire
{
    typename Iter::value_type sum=0;
    while(first1!=last1 && first2!=last2){
        sum+=*first1 * *first2;
    }
    return sum;
}

