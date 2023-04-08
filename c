 >>> from colour.utilities import is_trimesh_installed
    >>> vertices, faces, _outline = primitive_cube(1, 1, 1, 64, 64, 64)
    >>> XYZ_vertices = RGB_to_XYZ(
    ...     vertices["position"] + 0.5,
    ...     RGB_COLOURSPACE_sRGB.whitepoint,
    ...     RGB_COLOURSPACE_sRGB.whitepoint,
    ...     RGB_COLOURSPACE_sRGB.matrix_RGB_to_XYZ,
    ...     vertices["position"] + 0.5, RGB_COLOURSPACE_sRGB
    ... )
    >>> if is_trimesh_installed:
    ...     import trimesh
@@ -382,10 +379,7 @@ def plot_hull_section_contour(
    >>> from colour.utilities import is_trimesh_installed
    >>> vertices, faces, _outline = primitive_cube(1, 1, 1, 64, 64, 64)
    >>> XYZ_vertices = RGB_to_XYZ(
    ...     vertices["position"] + 0.5,
    ...     RGB_COLOURSPACE_sRGB.whitepoint,
    ...     RGB_COLOURSPACE_sRGB.whitepoint,
    ...     RGB_COLOURSPACE_sRGB.matrix_RGB_to_XYZ,
    ...     vertices["position"] + 0.5, RGB_COLOURSPACE_sRGB
    ... )
    >>> if is_trimesh_installed:
    
    ...     import trimesh
      }
    spd1 = SpectralDistribution(data_1, name="Custom 1")
    spd2 = SpectralDistribution(data_2, name="Custom 2")
    plt.close(plot_multi_sds([spd1, spd2], **arguments)[0])
    plot_kwargs = [
        {"use_sd_colours": True},
        {"use_sd_colours": True, "linestyle": "dashed"},
    ]
    plt.close(
        plot_multi_sds([spd1, spd2], plot_kwargs=plot_kwargs, **arguments)[0]
    )

    arguments["filename"] = os.path.join(
        output_directory, "Plotting_Plot_Single_CMFS.png"
@@ -390,10 +396,10 @@ def generate_documentation_plots(output_directory: str):
    arguments["filename"] = os.path.join(
        output_directory, "Plotting_Plot_Multi_CMFS.png"
    )
    cmfs = (
    cmfs = [
        "CIE 1931 2 Degree Standard Observer",
        "CIE 1964 10 Degree Standard Observer",
    )
    ]
    plt.close(plot_multi_cmfs(cmfs, **arguments)[0])

    arguments["filename"] = os.path.join(
@@ -546,7 +552,27 @@ def generate_documentation_plots(output_directory: str):
    )
    A = SDS_ILLUMINANTS["A"]
    D65 = SDS_ILLUMINANTS["D65"]
    plt.close(plot_sds_in_chromaticity_diagram([A, D65], **arguments)[0])
    annotate_kwargs = [
        {"xytext": (-25, 15), "arrowprops": {"arrowstyle": "-"}},
        {},
    ]
    plot_kwargs = [
        {
            "illuminant": SDS_ILLUMINANTS["E"],
            "markersize": 15,
            "normalise_sd_colours": True,
            "use_sd_colours": True,
        },
        {"illuminant": SDS_ILLUMINANTS["E"]},
    ]
    plt.close(
        plot_sds_in_chromaticity_diagram(
            [A, D65],
            annotate_kwargs=annotate_kwargs,
            plot_kwargs=plot_kwargs,
            **arguments,
        )[0]
    )

    arguments["filename"] = os.path.join(
        output_directory,
@@ -581,9 +607,16 @@ def generate_documentation_plots(output_directory: str):
        output_directory,
        "Plotting_Plot_RGB_Colourspaces_In_Chromaticity_Diagram.png",
    )
    plot_kwargs = [
        {"color": "r"},
        {"linestyle": "dashed"},
        {"marker": None},
    ]
    plt.close(
        plot_RGB_colourspaces_in_chromaticity_diagram(
            ["ITU-R BT.709", "ACEScg", "S-Gamut"], **arguments
            ["ITU-R BT.709", "ACEScg", "S-Gamut"],
            plot_kwargs=plot_kwargs,
            **arguments,
        )[0]
    )

@@ -923,9 +956,24 @@ def generate_documentation_plots(output_directory: str):
        output_directory,
        "Plotting_Plot_Planckian_Locus_In_Chromaticity_Diagram.png",
    )
    annotate_kwargs = [
        {"xytext": (-25, 15), "arrowprops": {"arrowstyle": "-"}},
        {"arrowprops": {"arrowstyle": "-["}},
        {},
    ]
    plot_kwargs = [
        {
            "markersize": 15,
        },
        {"color": "r"},
        {},
    ]
    plt.close(
        plot_planckian_locus_in_chromaticity_diagram(
            ["A", "B", "C"], **arguments
            ["A", "B", "C"],
            annotate_kwargs=annotate_kwargs,
            plot_kwargs=plot_kwargs,
            **arguments,
        )[0]
    )
