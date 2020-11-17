from setuptools import setup, Extension, find_packages

setup(
    name="Factorization",
    version="1.0",
    description="This is a math package",
    author="eos175",
    author_email="eos175@gmail.com",
    ext_modules=[
        Extension("factorization", sources=["factorization.cpp"])
    ]
)

