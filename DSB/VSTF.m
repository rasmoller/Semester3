%% Opgave 4.9
%Her er x = datamatrice, s = switch-variabel

function VSTF(x)

    v = istft(x);

    figure
    stft(v);
end
