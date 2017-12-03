let rows =
  Node.Fs.readFileAsUtf8Sync("./src/day2/input.txt")
  |> Js.String.split("\n")
  |> Array.map(
       (row) => Js.String.split("\t", row) |> Array.map((cellStr) => int_of_string(cellStr))
     );

let maxPerRow = rows |> Array.map((row) => Array.fold_left(max, 0, row));

let minPerRow = rows |> Array.map((row) => Array.fold_left(min, 9999999999999, row));

let minAndMaxPerRow = List.combine(Array.to_list(maxPerRow), Array.to_list(minPerRow));

let diffPerRow = List.map(((x, y)) => x - y, minAndMaxPerRow);

let sumOfDiff = List.fold_left((acc, x) => acc + x, 0, diffPerRow);

Js.log("SUM: " ++ string_of_int(sumOfDiff));