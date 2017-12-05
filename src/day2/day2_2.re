/* let cartesian = (l, l') => List.concat(List.map((e) => List.map((e') => (e, e'), l'), l)); */
/* let cart2 = (l1, l2) => Array.mapi((i, e) => i >0 ? e: , l1); */
/* let combineWith = (x, a, skipIndex) =>
   List.concat(List.mapi((index, e) => index === skipIndex ? [] : [(x, e)], a)); */
/* let map_partial = (f, xs) => {
     let prepend_option = (x, xs) =>
       switch x {
       | None => xs
       | Some(x) => [x, ...xs]
       };
     List.rev(List.fold_left((acc, x) => prepend_option(f(x), acc), [], xs));
   }; */
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

let a1 = [1, 2, 3, 4];

/* let olle = fold_lefti((n, acc, e) => acc + e + n, 0, a1);

   Js.log(olle); */
/* let x1 = map_partial((e) => Some(e), a1); */
let x2 = mapi_partial((n, e) => n === 2 ? None : Some(e), a1);

Js.log(Array.of_list(x2));

let combineWith = (x, a, skipIndex) =>
  mapi_partial((index, e) => index === skipIndex ? None : Some((x, e)), a);

/* let c2 = List.mapi((n, e) => combineWith(e, a1, n), a1); */
let c = combineWith(99, a1, 1);

Js.log(Array.of_list(c));
/* Js.log(Array.of_list(cartesian([1, 2, 3], [1, 2, 3]))); */
/* Js.log(Array.of_list(x1)); */