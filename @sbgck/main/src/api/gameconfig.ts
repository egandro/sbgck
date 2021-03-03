import { Board } from './board';
import { Material } from './material';
import { MP3 } from './mp3';


export interface GameConfig {
	name: string,
	boards: Board[],
	materials: Material[],
	mp3s: MP3[],
	mp3JsonFile: string
}
