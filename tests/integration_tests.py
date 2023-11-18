import os
import subprocess
import shutil

maps_folder = 'example_files/maps'
solved_folder = 'example_files/solved'
failed_folder = 'example_files/failed'
failed_count = 0
passed_count = 0
total_count = 0

if os.path.exists(failed_folder):
    shutil.rmtree(failed_folder)
os.makedirs(failed_folder)

for map_file in os.listdir(maps_folder):
    map_path = os.path.join(maps_folder, map_file)

    result = subprocess.run(['./setting_up', map_path], capture_output=True, text=True)

    solved_file_path = os.path.join(solved_folder, map_file)
    with open(solved_file_path, 'r') as solved_file:
        solved_content = solved_file.read()

    if result.stdout == solved_content:
        print(f"Test passed for {map_file}")
        passed_count += 1
        total_count += 1
    else:
        print(f"Test failed for {map_file}")
        failed_count += 1
        total_count += 1
        failed_file_path = os.path.join(failed_folder, map_file)
        with open(failed_file_path, 'w') as failed_file:
            failed_file.write(result.stdout)

print(f"Failed : {failed_count}/{total_count}")
print(f"Passed : {passed_count}/{total_count}")

if failed_count > 0:
    exit(1)
else:
    exit(0)
