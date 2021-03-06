CHAPTER 1: Multitasking OS Basics
    
        Useful Abstractions
        Memory Hierarchy and Caching Strategy
        Virtual Memory
        Virtual Addressing
        Process Memory Division Scheme
        The Roles of Binaries, Compiler, Linker, and Loader
   
CHAPTER 2: Simple Program Lifetime Stages

        Initial Assumptions
        Code Writing
        Compiling
        Linking
        Executable File Properties

CHAPTER 3: Program Execution Stages
    
        Importance of the Shell
        Kernel Role
        Loader Role
        Executing Program Entry Point

CHAPTER 4: The Impact Of Reusing Concept
    
        Static Libraries
        Dynamic Libraries
        Static vs. Dynamic Libraries Comparison Points
        Useful Comparison Analogies
        The Conclusion: The Impact of Binary Reuse Concept


CHAPTER 5: Working With Static Libraries
    
        Creating Static Library
        Using the Static Library
        Static Libraries Tips and Tricks

CHAPTER 6: Designing Dynamic Libraries: Basics
    
        Creating the Dynamic Library
        Designing Dynamic Libraries
        Dynamic Linking Modes

CHAPTER 7: Locating The Libraries
    
        Typical Library Use Case Scenarios
        Build Time Library Location Rules
        Runtime Dynamic Library Location Rules
        Linux Demo of Build Time and Runtime Conventions

CHAPTER 8: Designing Dynamic Libraries: Advanced Topics
    
        Why Resolved Memory Addresses Are a Must
        General Problem of Resolving References
        Problems Caused by Address Translation
        Linker-Loader Coordination
        Linker-Loader Coordination Implementation Techniques

CHAPTER 9: Handling Duplicate Symbols When Linking In Dynamic Libraries
    
        Duplicate Symbols Definition
        Duplicate Symbols Default Handling
        Duplicate Symbols Handling When Linking in Dynamic Libraries
        Analyses of Specific Duplicate Names Cases
        Final Remark: Linking Does Not Provide Any Kind of Namespace Inheritance


CHAPTER 10: Dynamic Libraries Versioning
    
        Gradation of Versions and their Impact on Backwards Compatibility
        Linux Dynamic Library Versioning Schemes
        Windows Dynamic Libraries Versioning
        CHAPTER 11: Dynamic Libraries: Miscellaneous Topics
            
        Plug-in Concept
        Tips and Tricks


CHAPTER 12: Linux Toolbox

        Quick Insight Tools
        Detailed Analysis Tools
        Deployment Phase Tools
        Runtime Analysis Tools
        Static Library Tools


CHAPTER 13: Linux How To???s
    
        Debugging the Linking
        Determining the Binary File Type
        Determining the Binary File Entry Point
        List Symbols
        List and Examine Sections
        List and Examine Segments
        Disassembling the Code
        Identifying the Debug Build
        Listing Load-time Dependencies
        Listing the Libraries Known to the Loader
        Listing Dynamically Linked Libraries
        Creating and Maintaining the Static Library
