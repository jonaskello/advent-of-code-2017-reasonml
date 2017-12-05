let fold_lefti = (f, seed, l) => {
  let (_, x) = List.fold_left(((n, acc), e) => (n + 1, f(n, acc, e)), (0, seed), l);
  x;
};

let mapi_partial = (f, xs) => {
  let prepend_option = (x, xs) =>
    switch x {
    | None => xs
    | Some(x) => [x, ...xs]
    };
  List.rev(fold_lefti((n, acc, x) => prepend_option(f(n, x), acc), [], xs));
};

let combineWith = (x, a, skipIndex) =>
  mapi_partial((index, e) => index === skipIndex ? None : Some((x, e)), a);

let a1 = [5, 9, 2, 8];

let pairsExludingSelf = List.concat(List.mapi((n, e) => combineWith(e, a1, n), a1));

let evenlyDividablePairs = List.filter(((a, b)) => a mod b === 0, pairsExludingSelf);

/* let c = combineWith(99, a1, 1); */
Js.log(Array.of_list(pairsExludingSelf));

Js.log(Array.of_list(evenlyDividablePairs));
/* Js.log(Array.of_list(cartesian([1, 2, 3], [1, 2, 3]))); */
/* Js.log(Array.of_list(x1)); */