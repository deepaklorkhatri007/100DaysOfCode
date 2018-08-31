# simple text to speech using Google TTS
from gtts import gTTS
import os
import sys
if len(sys.argv) == 2:
    tts = gTTS(text=repr(sys.argv[1]), lang='en')
    tts.save("text.mp3")
    for i in range (1,10):
        os.system("mpg123 text.mp3")
    os.system("rm text.mp3")
else :
    print("Usage : python3 tts.py 'say this'")
