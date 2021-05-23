import * as fs from 'fs';
import * as path from 'path';

export class FileManager {
    public assetFolder: string = '';

    fileExists(filename: string): boolean {
        if (!fs.existsSync(filename)) {
            return false;
        }
        return true;
    }

    readAsString(filename: string): string | null {
        if (!this.fileExists(filename)) {
            return null;
        }
        return fs.readFileSync(filename, 'utf8');
    }

    vfsResolveFile(baseFileName: string | null | undefined, hints?: string[]): string | null {
        if(baseFileName == null || baseFileName == undefined) {
            return null;
        }

        let filename = path.join(this.assetFolder, baseFileName);

        let fileExist = false;
        if (this.fileExists(filename)) {
            fileExist = true;
        }

        if(hints == null || hints == undefined) {
            hints = [];
            hints.push('mp3s');
            hints.push('boards');
            hints.push('assets');
        }

        if (fileExist == false) {
            for (var hint of hints) {
                filename = path.join(this.assetFolder, hint, baseFileName);

                if (this.fileExists(filename)) {
                    fileExist = true;
                    break;
                }
            }
        }

        if (!fileExist) {
            return null;
        }

        return filename;
    }

    vfsReadAsString(baseFileName: string, hints?: string[]): string | null {
        const filename = this.vfsResolveFile(baseFileName, hints);

        if (filename == null) {
            return null;
        }

        return fs.readFileSync(filename, 'utf8');
    }

}