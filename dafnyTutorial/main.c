//#include <stdlib.h>
//#include <stdio.h>
#include <limits.h>

/*@
  logic integer abs(integer x) = x < 0 ? -x : x;
*/

/*@
  requires INT_MIN < x;
  ensures \result == abs(x);
  assigns \nothing;
*/
int Abs(int x)
{
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}

//@ assigns \nothing;
void TestingAbs(void)
{
    int v= Abs(3);
    //@ assert 0 <= v;
    //@ assert 3 == v;
}

/********************************************************************
method MultipleReturns( x: int, y: int) returns (more: int, less: int)
  requires 0 < y
  ensures less < x < more
{
    more := x + y;
    less := x - y;
}
********************************************************************/

//@ logic integer max(int x, int y) = x < y ? y : x;

/*@
  ensures \result == max(a,b);
  assigns \nothing;
*/
int Max(int a, int b)
{
  if (a < b) {
    return b;
  }
  return a;
}

//@ assigns \nothing;
void TestingMax(void)
{
    int v = Max(-2, 3);
    //@ assert 3 <= v;
}

/*@
  logic integer fib(integer n) =
    n==0 ? 0 : (
      n==1 ? 1 : (
        fib(n-1) + fib(n-2)
      )
    );
*/


// for a bound on the growth of the Fibonacci sequence see:
// https://math.stackexchange.com/a/674567

// In order to prove that there is not integer overflow we need to prove
// an "easy" upper bound on the values of the Fibonacci Sequence. To do
// this we will need to (have the prover) invoke various theories about
// elementary mathematics. I *believe* these theories are located in Why3
// files located in:
//  - <OPAM_DIR>/share/frama-c/wp
//  - <OPAM_DIR>/share/frama-c/wp/why3
//  - <OPAM_DIR>/share/why3/stdlib

/*@
  requires 0 <= n ;
  requires \pow(2,n) < INT_MAX ;
  ensures \result == fib(n) ;
  assigns \nothing ;
*/
int ComputeFib(int n)
{
  if (n == 0) return 0;
  if (n == 1) return 1;
  int i = 2;
  int b = 1;
  int c = 1;
  //@ assert fib(1) < \pow(2,1);
  //@ assert fib(2) < \pow(2,2);
  /*@
    loop invariant 0 <= i <= n;
    loop invariant b == fib(i);
    loop invariant fib(i) < \pow(2,i) ;
    loop invariant fib(i-1) < \pow(2,i-1);
    loop invariant \pow(2,i-1) + \pow(2,i) < \pow(2,i+1);
    loop invariant fib(i-1) + fib(i) < \pow(2,i+1);
    loop invariant c == fib(i+1);
    loop   assigns \nothing;
    loop   variant n - i;
  */
  while (i < n)
  {
    int tmp = c;
    c = b+c;
    b = tmp;
    i = i + 1;
  }
  //@ assert i == n ;
  return b;
}

/********************************************************************
method Find(a : array<int>, key: int) returns (index: int)
  ensures 0 <= index ==> index < a.Length && a[index] == key
  ensures index < 0  ==> forall k :: 0 <= k < a.Length ==> a[k] != key
{
  index := 0;
  while index < a.Length
    invariant 0 <= index <= a.Length
    invariant forall k :: 0 <= k < index ==> a[k] != key
    decreases a.Length - index
  {
    if a[index] == key { return ; }
    index := index + 1;
  }
  index := -1;
}

method FindMax(a : array<int>) returns (index: int)
  ensures 0 <= index < a.Length ==> forall k :: 0 <= k < a.Length ==> a[k] <= a[index]
  ensures index < 0 ==> a.Length < 1
{
  if a.Length < 1 { return -1; }
      index  := 0;
  var i      := 0;
  var curMax := a[0];
  assert a[i] == curMax;
  assert a[index] == curMax;
  while i < a.Length
    invariant 0 <= i <= a.Length
    invariant 0 <= index < a.Length
    invariant  a[index] == curMax
    invariant forall k :: 0 <= k < i ==> a[k] <= curMax
    decreases a.Length - i
  {
    if i < a.Length && curMax < a[i] {
        index := i;
        curMax := a[index];
    }
    assert a[index] == curMax;
    i := i + 1;
  }
}

predicate sorted(a: array<int>)
  requires 0 < a.Length
  reads a
{
  forall j, k :: 0 <= j < k < a.Length ==> a[j] < a[k]
}

method BinarySearch(a: array<int>, key: int) returns (index: int)
  requires 0 < a.Length && sorted(a)
  ensures 0 <= index ==> index < a.Length && a[index] == key
  ensures index < 0 ==> forall k :: 0 <= k < a.Length ==> a[k] != key
{
  var curMin, curMax := 0, a.Length;

  while curMin < curMax
    invariant 0 <= curMin <= curMax <= a.Length
    invariant forall i ::
      0 <= i < a.Length && !(curMin <= i < curMax) ==> a[i] != key
    decreases curMax - curMin
  {
    var mid := (curMin + curMax) / 2;
    if a[mid] < key {
      curMin := mid + 1;
    } else if key < a[mid] {
      curMax := mid;
    } else {
      return mid ;
    }
  }
  return -1;
}

********************************************************************/

//@ assigns \nothing;
int main(void) {

	return 0;
}










