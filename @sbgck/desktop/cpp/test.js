const desktop = require('../build/Release/desktop');
console.log(desktop.hello());
console.log(desktop.version());
console.log(desktop.add(1, 3));
console.log(desktop.json({ foo: "bar", name: "my name"}));
var data = {
    name: "foo"
}
console.log(desktop.json(data));

