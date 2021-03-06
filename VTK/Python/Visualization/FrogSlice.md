### Description

This example uses a dataset derived from a frog. This data was prepared at Lawrence Berkeley National Laboratories and is included with their permission. The data was acquired by physically slicing the frog and photographing the slices. The original segmented data is in the form of tissue masks with one file per tissue. There are 136 slices per tissue and 15 different tissues. Each slice is 470 by 500 pixels.

To accommodate the volume readers we have in VTK, we processed the mask files and combined them all into one vtkMetaImageReader *.mhd* file. Integer numbers 1–15 to represent the 15 tissues. A similar process was done for the frog skin.

This example shows a photographic slice of frog (upper left), segmented frog (upper right) and composite of photo and segmentation (bottom). The purple color represents the stomach and the kidneys are yellow.
