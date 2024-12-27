import re
import os
from PyPDF2 import PdfReader, PdfWriter

def extract_instructions(objdump_file):
    """Extract unique assembly instructions from objdump output."""
    instructions = set()
    pattern = re.compile(r'\s+[a-f0-9]+:\s+[a-f0-9 ]+\s+([a-z]+)')

    with open(objdump_file, 'r') as f:
        for line in f:
            match = pattern.search(line)
            if match:
                instructions.add(match.group(1))

    return sorted(instructions)

def search_pdf_for_instructions(pdf_paths, instructions):
    """Search PDF(s) for information about the given instructions."""
    relevant_pages = {}

    for pdf_path in pdf_paths:
        reader = PdfReader(pdf_path)
        for i, page in enumerate(reader.pages):
            text = page.extract_text().lower()
            for instruction in instructions:
                if instruction in text:
                    if instruction not in relevant_pages:
                        relevant_pages[instruction] = []
                    relevant_pages[instruction].append((pdf_path, i + 1))

    return relevant_pages

def generate_custom_guide(relevant_pages, output_pdf):
    """Generate a smaller PDF with relevant pages."""
    writer = PdfWriter()

    for instruction, pages in relevant_pages.items():
        for pdf_path, page_num in pages:
            reader = PdfReader(pdf_path)
            writer.add_page(reader.pages[page_num - 1])

    with open(output_pdf, 'wb') as f:
        writer.write(f)

    print(f"Custom guide created: {output_pdf}")

if __name__ == "__main__":
    # Input files
    objdump_file = input("Enter the path to the objdump file: ").strip()
    pdf_paths = input("Enter the paths to the Intel manual PDFs, separated by commas: ").strip().split(',')
    pdf_paths = [path.strip() for path in pdf_paths]

    # Output file
    output_pdf = "custom_reference_guide.pdf"

    # Process
    print("Extracting instructions from objdump...")
    instructions = extract_instructions(objdump_file)

    print("Searching Intel manuals for instructions...")
    relevant_pages = search_pdf_for_instructions(pdf_paths, instructions)

    print("Generating custom reference guide...")
    generate_custom_guide(relevant_pages, output_pdf)

    print("Done!")

