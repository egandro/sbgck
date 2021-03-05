import { Audio } from '@sbgck/os-api';

const desktop = require('../../build/Release/desktop');

const player = require('play-sound')();

export class AudioImplementation implements Audio {
	playMp3(fileName: string): boolean {
		console.log("AudioImplementation says greetings from C++ ", desktop.version());
		// non blocking player
		player.play(fileName, (err: Error)=>{
			if (err) throw err
		});
		return true;
	}
}
