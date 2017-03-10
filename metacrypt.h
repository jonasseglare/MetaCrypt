#define tn typename
#define td typedef
#define tp template
#define sc static const
#define F struct
#define Q char
enum class Md {Encode,Decode};
tp <Q ... c> F S {};
tp <tn T> F Op {};
tp <Q x, Q ... y> F Op<S<x, y...>> {sc Q f = x; td S<y...> r; td S<y..., x> ro;};
tp <tn T, Q x> F Ad {};
tp <Q x, Q ... y> F Ad<S<y...>, x> {td S<y..., x> v;};
tp <Q x, tn T> F Cn {};
tp <Q x, Q ... y> F Cn<x, S<y...>> {td S<x, y...> v;};
tp <Q a, Q b> F Rg {td tn Cn<a, tn Rg<a+1, b>::v>::v v;};
tp <Q x> F Rg<x,x> {td S<x> v;};
tp <tn A, tn B> F Ct;
tp <tn A, tn B> F Ct {
  td Op<B> b; 
  td tn Ct<tn Ad<A, b::f>::v, tn b::r>::v v;
};
tp <tn A> F Ct<A, S<>> {td A v;};
tp <tn A, tn B> using ct = tn Ct<A, B>::v;
tp <Q x, Q y> using rg = tn Rg<x, y>::v;
td ct<ct<rg<'A', 'Z'>, rg<'0', '9'>>, S<' ', ',', '.', '?'>> CSet;
tp <tn T> F L {sc int v = 1 + L<tn Op<T>::r>::v;};
tp <> F L<S<>> {sc int v = 0;};
constexpr int mup(int x, int y) {return x<0? mup(x+y,y):x;}
tp <int n, tn T> F Nth {sc Q v =  Nth<mup(n-1,L<T>::v), tn Op<T>::ro>::v;};
tp <tn T> F Nth<0, T> {sc Q v = Op<T>::f;};
tp <Q x, tn T> F Fd {};
tp <Q x, Q y, Q ... z> F Fd<x, S<y, z...>> {sc int v = 1+Fd<x, S<z...>>::v;};
tp <Q x, Q ... y> F Fd<x,S<x,y...>> {sc int v = 0;};
tp <Q x> F Ind {sc int v = Fd<x, CSet>::v;};
constexpr int sg(Md m) {return m==Md::Encode? 1 : -1;}
tp <Md m, Q x, Q y> F Cd {sc Q v = Nth<sg(m)*Ind<x>::v + Ind<y>::v, CSet>::v;};
tp <Md m, tn K, tn X> F Tr;
tp <Md m, tn K, tn X> F Tr {
  td Op<K> k; 
  td Op<X> x; 
  td tn Cn<Cd<m, k::f, x::f>::v, tn Tr<m, tn k::ro, tn x::r>::v>::v v;
};
tp <Md m, tn K> F Tr<m,K,S<>> {td S<> v;};
