let input = Node.Fs.readFileAsUtf8Sync("./src/day2/input.txt");

let rowsRaw = Js.String.split("\n", input);

let rows =
  Array.map((row) => Array.map((a) => int_of_string(a), Js.String.split("\t", row)), rowsRaw);

Js.log(rows);