%% Opgave 4.8
%Her er x = analysesignal, fs = samplefrekvens, w = Window-Length, ov = Overlap-Length
%ov < w

function STF = STF(x, fs, w, ov)
    STF = stft(x, fs, 'Window', kaiser(w, 5), 'OverlapLength', ov);
end