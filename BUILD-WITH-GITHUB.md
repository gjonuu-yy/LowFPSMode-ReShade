# Build without installing a compiler

This project includes a GitHub Actions workflow that compiles the Windows x64 add-on on a hosted Windows runner.

1. Sign in to GitHub and create a new empty repository.
2. Upload the contents of this project folder to the repository (keep the `.github/workflows/build.yml` path).
3. Open the repository's **Actions** tab. If prompted, enable Actions.
4. Open **Build LowFPSMode ReShade add-on** and click **Run workflow** (or wait for the first push build).
5. When the run finishes successfully, open it and download the **LowFPSMode-addon64** artifact.
6. Extract the downloaded artifact; it contains `LowFPSMode.addon64`.

This cloud build still requires a GitHub account and a few upload/click steps, but no local Visual Studio, CMake, or C++ setup. The workflow fetches the official ReShade headers and builds the project for x64 Windows.

Pure Mode 1 may still block the resulting add-on. This workflow does not bypass FiveM restrictions and the add-on only disables ReShade effects; it does not remove GTA V's native fog or alter player visibility.
