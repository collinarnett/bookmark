{
  description = "simple booking program";

  inputs.nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable";
  inputs.pre-commit-hooks.url = "github:cachix/pre-commit-hooks.nix";
  inputs.flake-utils.url = "github:numtide/flake-utils";

  outputs = { self, nixpkgs, pre-commit-hooks, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let pkgs = nixpkgs.legacyPackages.${system};
      in rec {
        checks = {
          pre-commit-check = pre-commit-hooks.lib.${system}.run {
            src = ./.;
            hooks = {
              clang-format = {
                enable = true;
                types_or = [ "c" ];
              };
            };
          };
        };
        devShell = nixpkgs.legacyPackages.${system}.mkShell {
          buildInputs = with pkgs; [ gcc ];
          inherit (self.checks.${system}.pre-commit-check) shellHook;
        };
      });
}
