{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
    buildInputs = with pkgs; [ gcc cmake ncurses libpulseaudio ];
}
