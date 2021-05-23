const desktop = require('../build/Release/desktop');

console.log("typeof desktop.hellox", eval("typeof(desktop.hellox);"));
console.log("typeof desktop.hello", eval("typeof(desktop.hello);"));

console.log("hello", desktop.hello());

console.log("openCVversion", desktop.openCVversion());
console.log("soloudVersion", desktop.soloudVersion());

// console.log(desktop.add(1, 3));
// console.log(desktop.json({ foo: "bar", name: "my name"}));
// var data = {
//     name: "foo"
// }
// console.log(desktop.json(data));

// console.log(desktop.hello());
// console.log(desktop.json("dead beef"));

console.log(desktop.vfstest(__dirname));
