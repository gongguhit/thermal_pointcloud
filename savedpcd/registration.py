import os
import open3d as o3d
import numpy as np

# set the path to the folder containing the .pcd files
folder_path = "./"

# load the point clouds from files
pcd_files = sorted(os.listdir(folder_path))
pcd_list = []
for pcd_file in pcd_files:
    if ".pcd" in pcd_file:
        pcd_path = os.path.join(folder_path, pcd_file)
        pcd = o3d.io.read_point_cloud(pcd_path)
        pcd_list.append(pcd)

# perform registration
threshold = 0.02
trans_init = np.eye(4)
source_pcd = pcd_list[0]
for target_pcd in pcd_list[1:]:
    reg_p2p = o3d.pipelines.registration.registration_icp(
        source_pcd, target_pcd, threshold, trans_init,
        o3d.pipelines.registration.TransformationEstimationPointToPoint(),
        o3d.pipelines.registration.ICPConvergenceCriteria(max_iteration=200))
    source_pcd.transform(reg_p2p.transformation)
    
# save the result to a new .pcd file
output_file = "result.pcd"
o3d.io.write_point_cloud(output_file, source_pcd)

# visualize the registered point cloud
o3d.visualization.draw_geometries([source_pcd])
