var Jasmine = require('jasmine');
var SpecReporter = require('jasmine-console-reporter');
var noop = function() {};

var jrunner = new Jasmine();

jrunner.configureDefaultReporter({
    print: noop
}); // remove default reporter logs


// https://www.npmjs.com/package/jasmine-console-reporter
jasmine.getEnv().addReporter(new SpecReporter(
    {
        colors: 1,           // (0|false)|(1|true)|2
        cleanStack: 1,       // (0|false)|(1|true)|2|3
        verbosity: 4,        // (0|false)|1|2|(3|true)|4|Object
        listStyle: 'indent', // "flat"|"indent"
        timeUnit: 'ms',      // "ms"|"ns"|"s"
        timeThreshold: { ok: 500, warn: 1000, ouch: 3000 }, // Object|Number
        activity: false,     // boolean or string ("dots"|"star"|"flip"|"bouncingBar"|...)
        emoji: true,
        beep: false
    }
));

jrunner.loadConfigFile("./jasmine.json");
jrunner.execute();