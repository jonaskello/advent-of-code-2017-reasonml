let rows =
  Node.Fs.readFileAsUtf8Sync("./src/day2/input.txt")
  |> Js.String.split("\n")
  |> Array.map(
       (row) => Js.String.split("\t", row) |> Array.map((cellStr) => int_of_string(cellStr))
     );

Js.log(rows);