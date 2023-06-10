{
  description = "µC/OS-III experiments";

  inputs.mspgcc-ti.url = "github:42loco42/flakes?dir=mspgcc-ti";
  inputs.mspgcc-ti.inputs.nixpkgs.follows = "nixpkgs";

  outputs = { self, nixpkgs, ... }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };

      arm-cgt = pkgs.stdenv.mkDerivation rec {
        pname = "arm-cgt";
        version = "20.2.7.LTS";

        src = pkgs.fetchurl {
          url = "https://dr-download.ti.com/software-development/ide-configuration-compiler-or-debugger/MD-sDOoXkUcde/20.2.7.LTS/ti_cgt_tms470_20.2.7.LTS_linux-x64_installer.bin";
          hash = "sha256-aXvDge0AxS174Z1n8c32UaMGjsfDhATt1pbuf4Afs+g=";
        };

        unpackPhase = ":";
        installPhase = ''
          mkdir $out
          cd $out

          cp ${src} installer
          chmod 755 installer
          patchelf --set-interpreter "$(< "$NIX_CC/nix-support/dynamic-linker")" installer

          ./installer --mode unattended --prefix .
          rm installer

          dir="$(echo *)"
          mv "$dir/"* .
          rmdir "$dir"
          rm *uninstaller*

          PATH="$PATH:$PWD/bin"
          cd lib
          ./mklib --pattern rtsv7M4_T_be_v4SPD16_eabi.lib --parallel "$(nproc)"
        '';
      };

      jlink = pkgs.stdenv.mkDerivation rec {
        pname = "jlink";
        version = "7.88f";

        src = pkgs.fetchzip {
          url = "https://eleonora.gay/foo/8f5ddeace61a38aab47a450117dd6526d9dd25c32234ab793cac0b0412b8eeab-jlink-v788f.tgz";
          hash = "sha256-KQ73+GN7o6bin/w9hqdwDG09S2uXGqlK/87wwqp1n6c=";
        };

        installPhase = ''
          mkdir "$out"
          mv * "$out"
          cd "$out"
          mkdir bin
          find -maxdepth 1 -name 'J*' -exec ln -sr {} bin \;
        '';
      };
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        packages = with pkgs; [
          arm-cgt
          bashInteractive
          jlink
        ];

        ARM_CGT = "${arm-cgt}";
      };
    };
}
