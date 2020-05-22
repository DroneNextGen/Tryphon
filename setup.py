from setuptools import setup

setup(
    name='tryphon',
    version='0.1.0',    
    description='A simple, robust and lightweight communication protocol',
    url='https://github.com/DroneNextGen/Tryphon',
    author='Clément Trassoudaine',
    author_email='clement.trassoudaine@eurecom.fr',
    license='MIT',
    install_requires=[],
    packages=['tryphon'],
    package_dir={'tryphon': 'python_bindings'},
    package_data={'tryphon': ['libtryphon.so']},
)
