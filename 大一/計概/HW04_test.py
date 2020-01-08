import wave
sound = wave.open("./11025.wav","rb")
nchannels, sampwidth, framerate, nframes, comptype, compname = sound.getparams()
print(framerate,nframes)