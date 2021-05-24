import { Context, State, StateMachine } from "../src/modules";


class Solid extends State {
    name = 'Solid';
    transitions = [
        {
            transition: "melt",
            to: "Liquid"
        }
    ];

    on(ctx: Context): void {
        if (ctx.from == 'liquid') {
            console.log(' ... good bye');
        } else {
            this.transitionTo('melt');
        }
    }
}

class Liquid extends State {
    name = 'Liquid';
    transitions = [
        {
            transition: "freeze",
            to: "Solid"
        },
        {
            transition: "vaporize",
            to: "Gas"
        }
    ];

    on(ctx: Context): void {
        if (ctx.from == 'solid') {
            this.transitionTo('vaporize');
        } else {
            this.transitionTo('freeze');
        }

    }
}

class Gas extends State {
    name = 'Gas';
    transitions = [
        {
            transition: "condense",
            to: "Liquid"
        }
    ];

    on(ctx: Context): void {
        this.transitionTo('condense');
    }
}

// async function iframePortal(): Promise<Portal> {
//     const root = document.createElement("div");
//     document.body.appendChild(root);
//     // ...
// };

describe("Dummy Test", () => {

    // https://medium.com/@RupaniChirag/writing-unit-tests-in-typescript-d4719b8a0a40
    // https://www.innoq.com/en/blog/ts-jasmine-karma/
    // it("Simple communication", async () => {
    //     const { port1, port2, cleanup } = await iframePortal();

    //     const promise = receiveSingleMessage(port2);
    //     port1.postMessage("hello");
    //     await expectAsync(promise).toBeResolved("hello");

    //     cleanup();
    // });

    it('add', function () {
        const result = 5 + 2;
        expect(result).toBe(7);
    });

    it('sub', function () {
        const result = 5 - 2;
        expect(result).toBe(3);
    });

    it('statesTest', function () {
        const states: State[] = [
            new Solid(), new Liquid(), new Gas()
        ];

        const sm = new StateMachine(states);
        sm.verbose = true;
        //sm.run('solid');
        sm.run('liquid');


        expect(sm.fsm.state).toBe('solid');
    });

});