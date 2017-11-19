import java.math.BigInteger;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main{
    private static int S, vis2 = 1;
    private static int[] caseBase = new int[400];
    private static int[] used = new int[1000030];
    private static ArrayList < Integer > divisores = new ArrayList < Integer > ();
    private static ArrayList < Integer > v = new ArrayList < Integer > ();
    private static ArrayList < Integer > primes = new ArrayList < Integer > ();
    private static long[] poww = new long[100010];
    private static long[] L = new long[100010];
    private static long C = 5381;
    private static String str;
    public static void main(String[] args) {
        Scanner input = new Scanner( System.in ); 
        int n = 0; 
        str = input.nextLine();
        //System.out.println(str);
        n = input.nextInt();
        powwB();
        sieve(100000);
        S = str.length();
        Lcalc();
        System.out.println(necklaces(n));
    }

    public static void powwB(){
      poww[0] = 1L;
      for(int i = 1; i < 100010; i++) poww[i] = poww[i-1] * 33;
      Integer c = (int)'a';
      for(int i = 0; i < 26; i++){ 
          v.add(c-(int)'a'); c++; 
      }
      Collections.shuffle( v );
    }

    public static void Lcalc(){
      L[0] = C;  
      //System.out.println(str);                          //;
      for(int i = 0; i < S; i++ ){
         L[i+1] = L[i] * 33L + v.get(str.charAt(i)-'a');//L[i].multiply(BigInteger.valueOf(33)).add(BigInteger.valueOf(v.get(str.charAt(i)-'a')));
        //System.out.printf("%c",opa[i]);
      }
    }

    public static long calc_hash(int a, int b){
      return (L[b] - (L[a] * poww[b-a]));
    }

    public static BigInteger Manakera(int n){
      Map <BigInteger, Integer> mapa = new HashMap<BigInteger, Integer>();
      /* impar */
      ArrayList < Integer > d1 = new ArrayList < Integer > ();
      ArrayList < Integer > d2 = new ArrayList < Integer > ();
      for(int i=0; i <= n; i++){ d1.add(0); d2.add(0); }
      //System.out.println(d1.size());
      int l=0, r=-1, sum = 0;
      for (int i=0; i<n; ++i) {
          if( caseBase[str.charAt(i)] != vis2 ) sum++;
          caseBase[str.charAt(i)] = vis2;
          int k = (i > r ? 0 : Math.min (d1.get(l+r-i), r-i)) + 1;
          while (i+k < n && i-k >= 0 && str.charAt(i+k) == str.charAt(i-k)){
              BigInteger h = BigInteger.valueOf(calc_hash(i-k,i+k));
              if(!(i+k == i-k)) mapa.put(h,1);
              ++k;
          }  
          k--;
          d1.set(i,k);
          if (i+k > r){
              l = i-k; r = i+k;
          }
      }
      /* par */
      l=0; 
      r=-1;
      for (int i = 0; i < n; ++i) {
          int k = (i>r ? 0 : Math.min (d2.get(l+r-i+1), r-i+1)) + 1;
          while (i+k-1 < n && i-k >= 0 && str.charAt(i+k-1) == str.charAt(i-k)){
              BigInteger h = BigInteger.valueOf(calc_hash(i-k,i+k-1));
              if( !(i+k-1 == i-k) ) mapa.put(h,1);
              ++k;
          }  
          k--;
          d2.set(i,k);
          if (i+k-1 > r){
              l = i-k;
              r = i+k-1;
          }
      }
      //cout << mapa.size() << endl;
      //REP(i,n) cout << d1[i] << " ~ " << d2[i] << endl;
      return BigInteger.valueOf(mapa.size() + sum);
    }

    public static void divisors( int n ) {
      int maxP = (int) Math.sqrt(n) + 2;
      for( int i = 0; i < 610; i++ ) used[i] = 0;
      for(int i = 1; i <= maxP; i++ ){ 
        if ( n % i == 0 ) {
            if( used[i] == 0 ) divisores.add(i);
            used[i] = 1;
            if( used[n/i] == 0 ) divisores.add(n/i);
            used[n/i] = 1;
        }
      }
    }

    public static void sieve( long upp ){
        BitSet btset = new BitSet (100010);
        btset.set(0, 100010, false);
        long _sieve_size = upp + 1L;
        btset.set(0);
        btset.set(1);
        for( long i = 2L; i <= _sieve_size; i++ ) 
            if( btset.get((int)i) == false){
                for( long  j = i * i; j <= _sieve_size; j += i ) btset.set((int) j);
                primes.add((int)i);
            }
    }

    public static long  EulerPhi( long  n ){
        long  pf_idx = 0L;
        long pf = primes.get((int)pf_idx);
        long ans = n;
        while( pf * pf <= n ){
            if( n % pf == 0L ) ans -=ans / pf;
            while( n % pf == 0L ) n /= pf;
            ++pf_idx;
            pf = primes.get((int)pf_idx);
        } 
        if( n != 1 ) ans -= ans / n;
        return ans;
    }

    public static BigInteger necklaces( int n ){
        divisors( n );
        int tam = divisores.size();
        BigInteger ans = BigInteger.ZERO;
        //System.out.println(str.length());
        BigInteger k = Manakera(str.length());
        //return k;
        //System.out.println(k);
        BigInteger d = BigInteger.valueOf(n);
        BigInteger d2 = BigInteger.valueOf(2);
        //REP(i,10) cout << EulerPhi((int64)i+1) << "\n";
        for(int i = 0; i < tam; i++ )
            ans = ans.add(BigInteger.valueOf(EulerPhi(divisores.get(i))).multiply(k.pow( n/divisores.get(i))));
        ans = ans.divide(d);
        //if( !(n & 1) )
        //    ans = ((d2*ans) + (((k + bigint(1)) * k.pow(n/2))))/(d2*d2); 
        //else
        //    ans = (ans + (k.pow((n+1) >> 1))) / d2;
        if( (n % 2) != 0  ){
            ans = (ans.add(k.pow((n+1)>>1))).divide(d2);
        }   
        else{
            ans = (ans.add(((k.add(BigInteger.ONE)).multiply(k.pow(n>>1))).divide(d2))).divide(d2);
        }
        return ans;
      } 
}