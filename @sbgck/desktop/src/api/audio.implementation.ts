import { Audio } from '@sbgck/os-api';

const addon = require('../../build/Release/addon');

const player = require('play-sound')();

export class AudioImplementation implements Audio {
	playMp3(fileName: string): boolean {
		console.log("AudioImplementation says greetings from C++ ", addon.hello());
		// non blocking player
		player.play(fileName, (err: Error)=>{
			if (err) throw err
		});
		return true;
	}
}
