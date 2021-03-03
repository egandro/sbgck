import { Audio } from '@sbgck/os-api';

const player = require('play-sound')();

export class AudioImplementation implements Audio {
	playMp3(fileName: string): boolean {
		// blocking player
		player.play(fileName, (err: Error)=>{
			if (err) throw err
		});
		return true;
	}
}
