let rows =
  Node.Fs.readFileAsUtf8Sync("./src/day2/input.txt")
  |> Js.String.split("\n")
  |> Array.map(
       (row) => Js.String.split("\t", row) |> Array.map((cellStr) => int_of_string(cellStr))
     );

let maxPerRow = rows |> Array.map((row) => Array.fold_left(max, 0, row));

let minPerRow = rows |> Array.map((row) => Array.fold_left(min, 9999999999999, row));

let combineArrays = (left, right) => Array.mapi((n, x) => (x, right[n]), left);

let minAndMaxPerRow = combineArrays(maxPerRow, minPerRow);

let diffPerRow = Array.map(((x, y)) => x - y, minAndMaxPerRow);

let sumOfDiff = Array.fold_left((acc, x) => acc + x, 0, diffPerRow);

Js.log("SUM: " ++ string_of_int(sumOfDiff));