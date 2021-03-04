import { Board } from './board';
import { Asset } from './asset';
import { MP3 } from './mp3';


export interface GameConfig {
	name: string,
	boards: Board[],
	assets: Asset[],
	mp3s: MP3[],
	mp3JsonFile: string
}
